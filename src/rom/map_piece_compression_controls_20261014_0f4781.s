.setcpu "65816"
.segment "CODE"
.org $4781
map_control_0f4781:
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
