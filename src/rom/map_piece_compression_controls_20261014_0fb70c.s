.setcpu "65816"
.segment "CODE"
.org $B70C
map_control_0fb70c:
    .byte $E0 ; previous-row copy escape
    .byte $AB ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
