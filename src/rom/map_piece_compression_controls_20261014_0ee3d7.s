.setcpu "65816"
.segment "CODE"
.org $E3D7
map_control_0ee3d7:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
