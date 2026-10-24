.setcpu "65816"
.segment "CODE"
.org $F250
map_control_0ef250:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
