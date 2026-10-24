.setcpu "65816"
.segment "CODE"
.org $D617
map_control_0ed617:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
