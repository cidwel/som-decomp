.setcpu "65816"
.segment "CODE"
.org $CB7E
map_control_0ecb7e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
