.setcpu "65816"
.segment "CODE"
.org $D938
map_control_0ed938:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
