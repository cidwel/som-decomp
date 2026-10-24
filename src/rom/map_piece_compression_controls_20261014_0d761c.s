.setcpu "65816"
.segment "CODE"
.org $761C
map_control_0d761c:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $3C ; distance low bit/count
