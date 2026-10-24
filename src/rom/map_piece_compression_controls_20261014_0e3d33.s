.setcpu "65816"
.segment "CODE"
.org $3D33
map_control_0e3d33:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
