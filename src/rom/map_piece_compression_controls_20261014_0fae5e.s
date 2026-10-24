.setcpu "65816"
.segment "CODE"
.org $AE5E
map_control_0fae5e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
