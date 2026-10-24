.setcpu "65816"
.segment "CODE"
.org $B42E
map_control_0eb42e:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
