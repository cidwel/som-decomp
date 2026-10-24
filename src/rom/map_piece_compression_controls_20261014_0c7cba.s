.setcpu "65816"
.segment "CODE"
.org $7CBA
map_control_0c7cba:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
