.setcpu "65816"
.segment "CODE"
.org $5A05
map_control_0c5a05:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
