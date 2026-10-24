.setcpu "65816"
.segment "CODE"
.org $8EA1
map_control_0e8ea1:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
