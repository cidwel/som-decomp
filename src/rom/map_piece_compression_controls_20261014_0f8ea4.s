.setcpu "65816"
.segment "CODE"
.org $8EA4
map_control_0f8ea4:
    .byte $E9 ; backreference distance high bits
    .byte $17 ; distance low bit/count
