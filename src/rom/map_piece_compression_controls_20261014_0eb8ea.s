.setcpu "65816"
.segment "CODE"
.org $B8EA
map_control_0eb8ea:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
