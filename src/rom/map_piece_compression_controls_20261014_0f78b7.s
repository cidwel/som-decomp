.setcpu "65816"
.segment "CODE"
.org $78B7
map_control_0f78b7:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
