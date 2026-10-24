.setcpu "65816"
.segment "CODE"
.org $BE39
map_control_0dbe39:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $52 ; row-distance/count
