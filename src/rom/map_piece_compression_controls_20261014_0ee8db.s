.setcpu "65816"
.segment "CODE"
.org $E8DB
map_control_0ee8db:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $49 ; distance low bit/count
