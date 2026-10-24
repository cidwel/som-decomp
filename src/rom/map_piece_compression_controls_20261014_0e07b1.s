.setcpu "65816"
.segment "CODE"
.org $07B1
map_control_0e07b1:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
