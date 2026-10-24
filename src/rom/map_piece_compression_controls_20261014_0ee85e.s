.setcpu "65816"
.segment "CODE"
.org $E85E
map_control_0ee85e:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
