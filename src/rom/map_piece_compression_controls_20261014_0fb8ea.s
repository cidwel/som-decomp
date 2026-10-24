.setcpu "65816"
.segment "CODE"
.org $B8EA
map_control_0fb8ea:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
