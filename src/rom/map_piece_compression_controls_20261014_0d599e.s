.setcpu "65816"
.segment "CODE"
.org $599E
map_control_0d599e:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
