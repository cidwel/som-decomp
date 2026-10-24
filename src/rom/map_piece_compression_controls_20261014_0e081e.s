.setcpu "65816"
.segment "CODE"
.org $081E
map_control_0e081e:
    .byte $F6 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
