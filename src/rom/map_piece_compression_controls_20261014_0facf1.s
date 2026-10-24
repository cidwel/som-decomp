.setcpu "65816"
.segment "CODE"
.org $ACF1
map_control_0facf1:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
