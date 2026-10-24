.setcpu "65816"
.segment "CODE"
.org $2146
map_control_0f2146:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
