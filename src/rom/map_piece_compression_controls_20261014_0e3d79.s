.setcpu "65816"
.segment "CODE"
.org $3D79
map_control_0e3d79:
    .byte $F2 ; progressive-copy count
    .byte $E4 ; previous-row copy count
