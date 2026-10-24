.setcpu "65816"
.segment "CODE"
.org $622E
map_control_0f622e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
