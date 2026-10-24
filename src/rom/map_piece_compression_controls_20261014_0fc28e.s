.setcpu "65816"
.segment "CODE"
.org $C28E
map_control_0fc28e:
    .byte $CC ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
