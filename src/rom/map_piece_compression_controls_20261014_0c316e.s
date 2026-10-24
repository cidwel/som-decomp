.setcpu "65816"
.segment "CODE"
.org $316E
map_control_0c316e:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
