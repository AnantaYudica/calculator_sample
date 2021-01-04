ECHO off

SET _base_dir=%~dp0
SET __base_dir=%_base_dir:\=/%

PUSHD "%__base_dir%angular"

CALL %__base_dir%node_modules\\.bin\\ng b calculator-sample --output-path "%__base_dir%.build/dist/" --base-href "%__base_dir%.build/dist/"

POPD
