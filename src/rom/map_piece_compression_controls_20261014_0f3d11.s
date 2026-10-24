.setcpu "65816"
.segment "CODE"
.org $3D11
map_control_0f3d11:
    .byte $E1 ; previous-row copy count
