.setcpu "65816"
.segment "CODE"
.org $DB8E
map_control_0fdb8e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
