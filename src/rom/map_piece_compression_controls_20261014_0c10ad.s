.setcpu "65816"
.segment "CODE"
.org $10AD
map_control_0c10ad:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
