.setcpu "65816"
.segment "CODE"
.org $326A
map_control_0f326a:
    .byte $C9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
