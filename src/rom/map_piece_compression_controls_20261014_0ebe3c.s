.setcpu "65816"
.segment "CODE"
.org $BE3C
map_control_0ebe3c:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
