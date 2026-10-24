.setcpu "65816"
.segment "CODE"
.org $98B8
map_control_0e98b8:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
