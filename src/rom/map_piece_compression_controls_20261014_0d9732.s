.setcpu "65816"
.segment "CODE"
.org $9732
map_control_0d9732:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
