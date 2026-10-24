.setcpu "65816"
.segment "CODE"
.org $6CBE
map_control_0f6cbe:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $A1 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
