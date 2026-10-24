.setcpu "65816"
.segment "CODE"
.org $391E
map_control_0f391e:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
