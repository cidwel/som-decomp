.setcpu "65816"
.segment "CODE"
.org $E5B1
map_control_0ee5b1:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $8F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
