.setcpu "65816"
.segment "CODE"
.org $3D36
map_control_0e3d36:
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
