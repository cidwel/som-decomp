.setcpu "65816"
.segment "CODE"
.org $DC0A
map_control_0edc0a:
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
