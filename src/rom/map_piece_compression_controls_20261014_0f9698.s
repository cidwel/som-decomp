.setcpu "65816"
.segment "CODE"
.org $9698
map_control_0f9698:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
