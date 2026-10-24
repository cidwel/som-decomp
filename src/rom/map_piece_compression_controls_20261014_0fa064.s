.setcpu "65816"
.segment "CODE"
.org $A064
map_control_0fa064:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $F1 ; progressive-copy count
