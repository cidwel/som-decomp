.setcpu "65816"
.segment "CODE"
.org $C29E
map_control_0ec29e:
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
