.setcpu "65816"
.segment "CODE"
.org $19AF
map_control_0d19af:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
