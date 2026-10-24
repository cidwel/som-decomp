.setcpu "65816"
.segment "CODE"
.org $EDA1
map_control_0eeda1:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
