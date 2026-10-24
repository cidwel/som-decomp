.setcpu "65816"
.segment "CODE"
.org $7B3E
map_control_0c7b3e:
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $6F ; row-distance/count
