.setcpu "65816"
.segment "CODE"
.org $AA61
map_control_0faa61:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
