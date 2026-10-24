.setcpu "65816"
.segment "CODE"
.org $6707
map_control_0f6707:
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
