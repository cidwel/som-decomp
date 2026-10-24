.setcpu "65816"
.segment "CODE"
.org $A0EE
map_control_0ea0ee:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
