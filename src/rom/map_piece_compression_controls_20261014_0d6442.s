.setcpu "65816"
.segment "CODE"
.org $6442
map_control_0d6442:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
