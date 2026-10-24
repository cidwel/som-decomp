.setcpu "65816"
.segment "CODE"
.org $9300
map_control_0d9300:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
