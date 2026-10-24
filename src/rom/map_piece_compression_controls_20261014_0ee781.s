.setcpu "65816"
.segment "CODE"
.org $E781
map_control_0ee781:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
