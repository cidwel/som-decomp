.setcpu "65816"
.segment "CODE"
.org $E687
map_control_0ee687:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $99 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B2 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
