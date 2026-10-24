.setcpu "65816"
.segment "CODE"
.org $663E
map_control_0d663e:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
