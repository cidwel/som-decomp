.setcpu "65816"
.segment "CODE"
.org $0807
map_control_0d0807:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $5E ; row-distance/count
